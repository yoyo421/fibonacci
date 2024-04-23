const std = @import("std");
const builtin = @import("builtin");
const print = std.debug.print;

pub const DEBUG = (builtin.mode == std.builtin.OptimizeMode.Debug);
var gpa = std.heap.GeneralPurposeAllocator(.{}){};
const allocator = gpa.allocator();

// Function to calculate the Fibonacci number at a given index
fn fibonacci(n: u32) u64 {
    if (n <= 1) return n;

    var prev: u64 = 0;
    var current: u64 = 1;
    var next: u64 = 0;

    for (1..n) |value| {
        if (comptime DEBUG) print("index at: {}\n", .{value});
        next = prev + current;
        prev = current;
        current = next;
    }

    return current;
}

pub fn main() !void {
    defer _ = gpa.deinit();
    var args = std.process.argsWithAllocator(allocator) catch |err| {
        try print("Error: {}\n", err);
        return err;
    };
    defer args.deinit();

    // Skip the first argument, which is the program name.
    _ = args.next();

    const fibonacci_str: []const u8 = args.next() orelse return error.MissingArgument;

    const fibonacci_index = std.fmt.parseUnsigned(u32, fibonacci_str, @as(u8, 10)) catch |err| {
        print("Error: {}\n", .{err});
        return err;
    };

    const result = fibonacci(fibonacci_index);
    print("Fibonacci number at index {} is {}\n", .{ fibonacci_index, result });
    return;
}

test "fibonacci" {
    const result = fibonacci(10);
    try std.testing.expectEqual(55, result);
}
