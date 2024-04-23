Compile cpp `fibonacci.cpp`:

```sh
g++ fibonacci.cpp -o out/fibonacci_cpp -O3
```

Compile c `fibonacci.c`:

```sh
g++ fibonacci.c -o out/fibonacci_c -O3
```

Compile zig `fibonacci.zig`:

```sh
zig build-exe ./fibonacci.zig -O ReleaseFast -fstrip -fsingle-threaded -target x86_64-linux --name fibonacci_zig && rm ./fibonacci_zig.o && mv ./fibonacci_zig ./out/
```

measure time:

```sh
repeat_for=100
fibonacci_number=45

start_cpp=$(date +%s%N)
for i in `seq 1 $repeat_for`; do ./out/fibonacci_cpp $fibonacci_number; done
end_cpp=$(date +%s%N)

start_c=$(date +%s%N)
for i in `seq 1 $repeat_for`; do ./out/fibonacci_c $fibonacci_number; done
end_c=$(date +%s%N)

start_zig=$(date +%s%N)
for i in `seq 1 $repeat_for`; do ./out/fibonacci_zig $fibonacci_number; done
end_zig=$(date +%s%N)
echo "C++: $(( ($end_cpp-$start_cpp) / $repeat_for )) ns"
echo "C  : $(( ($end_c  -$start_c  ) / $repeat_for )) ns"
echo "Zig: $(( ($end_zig-$start_zig) / $repeat_for )) ns"
```