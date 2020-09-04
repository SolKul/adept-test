# テンプレート関数orクラステンプレート内で、別のテンプレートクラス内のテンプレートメソッドを呼び出す

テンプレート関数orクラステンプレート内で、別のテンプレートクラス内のテンプレートメソッドを呼び出したときに

```bash
error: expected primary-expression before '>' token
```

上のエラーが出る。

テンプレートメソッドを呼び出す際に、
```
t.template func<int>()
```
とする。

http://wiki.xsqi.net/index.php?%A5%D7%A5%ED%A5%B0%A5%E9%A5%E0%2FC%2B%2B


https://stackoverflow.com/questions/51553397/calling-a-template-method-on-a-class-template-parameter


https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords