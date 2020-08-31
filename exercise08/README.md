# debug with gdb

```bash
$ g++ source.cpp -g -O0 -o a.out
```

でコンパイルして、
```bash
$ gdb a.out
```
でデバッグ

```
break main
run
```
でデバッグ開始できる。

# Debugging C++ program using Template

https://stackoverflow.com/questions/24957363/how-to-print-evaluate-c-template-functions-in-gdb

```c++
template <typename T>
T add_tem(T x, T y){
    return x + y;
}
```

debugging c++ programing using template as shown above with gdb.

テンプレートは実行されて初めてインスタンス化(実体化)  する
具体的にはmain関数の中で、

```c++
int z = add_tem(3,4);
```

と書いてあると、コンパイル中に、

```c++
add_tem<int>(int,int)(3,4)
```

と実体化する。

そしてこれは`gdb`のデバッグ中に

```bash
(gdb) print add_tem(3,4)
```
としても使えない。

なぜなら、実体化してsymbolとして存在しているのは`add_tem<int>(int,int)(3,4)`であり、`add_tem(int x,int y)`ではないからだ。  
gdbで実行するには、
```bash
(gdb) print add_tem<int>(int,int)(3,4)
```
と実体化した形式と同じ形式なら実行できる。

どういう形式で実体化しているかは複雑なプログラムの場合分かりづらい。
その場合

```
(gdb) maint print symbols filename.txt
```
でfilename.txtにそのとき実体化しているsymbol一覧が見れるので検索するといい。