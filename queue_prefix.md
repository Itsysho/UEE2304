# Queue Prefix

- Please write the program in C/C++
- Please implement both questions with queue
- You get 0 point if you do not write the program with queue

One way to evaluate a prefix expression is to use a queue. To evaluate the expression, scan it repeatedly until you know the final expression value. In each scan read the tokens and store them in a queue. In each scan replace an operator that is followed by two operands with their calculated values. For example, the following expression is a prefix expression that is evalu- ated to 159:

```
- + * 9 + 2 8 * + 4 8 6 3
```

We scan the expression and store it in a queue. During the scan when an operator is followed by two operands, such as + 2 8, we put the result, 10, in the queue.
After the first scan, we have

```
- + * 9 10 * 12 6 3
```

After the second scan, we have

```
- + 90 72 3
```

After the third scan, we have

```
- 162 3
```

After the fourth scan, we have

```
159
```

Write a C program to evaluate a prefix expression.

Note

- 請自行實作 Queue，不能使用 StandardLibrary 的容器(Container)。
- 實作之 Queue 應符合 FIFO(First in First out)的使用原則。
- input/output 皆使用標準串流(stdin/stdout)，如果沒有特殊情況，就是
  指使用 scanf/cin 跟 printf/cout，以下為規範說明:
  - 首先輸入一個正整數 n(<=100)，代表接下來會有 n 組測資。
  - 每一組測資包含一個正整數 m(3<=m<=200)跟一串 prefix expression S，m 代表 S 由多少個 token(運算符+數字)所組成。
  - 運算符為基本四則運算，用+-\*/表示;數字則為絕對值小於 1000 之整數。每個 token 之間用一個空格隔開。
  - S 依題目敘述計算完畢後，將結果 output 出來並換行，繼續 input 下一組測資。
  - n 組測資的結果輸出完畢後，結束程式即可。
  - 單次計算過程若涉及小數，請將結果的小數位無條件捨去後
    再進行後面的操作。
        e.g:
        1. `/ / 30 4 3` -> `(30/4)/3` -> `7/3->2`
        1. `/ -5 2` -> `-5/2` -> `-2`
  - 計算過程跟結果皆不會出現超過 ±10^7 外的數值。
  - 不會出現無法計算的 S。

    e.g: `+ + 2 2` or `/ 1 0`
