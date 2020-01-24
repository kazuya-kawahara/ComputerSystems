・ソースの説明
Queueの定義を(要素,後者のアドレス,前者のアドレス)の三組とした。
それぞれの関数を要件通りに愚直に実装した。

・感想
低レベルなCでのデータ構造の実装を通して、コンピュータ内部の処理の仕方の一部を学べた。

・実行例
以下では
1	1put
1 3	3put
1 3 5	5put
1 3	5delete
3	get
display
となる様子をコピーアンドペーストしたものである

PS C:\Users\Owner\Documents\ComputerSystems\2> gcc .\Queue.c
PS C:\Users\Owner\Documents\ComputerSystems\2> .\a.exe
0: finish
1: put
2: get
3: delete
4: display
1
what number will you put?
1
1 was put.

0: finish
1: put
2: get
3: delete
4: display
1
what number will you put?
3
3 was put.

0: finish
1: put
2: get
3: delete
4: display
1
what number will you put?
5
5 was put.

0: finish
1: put
2: get
3: delete
4: display
4
1: 1
2: 3
3: 5

0: finish
1: put
2: get
3: delete
4: display
3
what number will you delete?
5
5 was deleted.

0: finish
1: put
2: get
3: delete
4: display
2

0: finish
1: put
2: get
3: delete
4: display
4
1: 3

0: finish
1: put
2: get
3: delete
4: display
0
finish!