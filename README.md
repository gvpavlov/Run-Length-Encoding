# Run-Length Encoding
[Run-Length Encoding](https://en.wikipedia.org/wiki/Run-length_encoding) проект по ООП във ФМИ.

# Description
Реализирани са:
- конструктор по низ (кодиране)
- операция за преобразуване до тип низ (декодиране)
- операция за извеждане (<<)
- голяма четворка
- операция за индексиране [], която да връща пореден символ в даден RLE списък
без да го декодира
- операции +, += за конкатениране на два RLE списъка
- операция ++ (в префиксен и постфиксен вариант), който добавя към даден RLE
списък още един символ, който е същият като последният в него. Ако операцията
се изпълни над празен списък, той не се променя
- операция (в префиксен и постфиксен вариант), която премахва последния
символ от списъка. Ако операцията се изпълни над празен списък, той не се
променя.
- операция () за намиране на подсписък от дадена позиция и с дадена дължина
- операция, която изтрива последователност от символи от дадена позиция
- операции ==, != за сравнение на два списъка
- операции A < B, A <= B, B > A, B >= A, който проверяват дали A e (строг) подсписък
на B, т.е. низът, кодиран от RLE списъка A е (строг) подниз на низа, кодиран от
RLE списъка B.
- едноместна операция *, която по дадено RLE кодиране на низ, да построява
честотната таблица на низа (за всеки символ, който се среща в низа, се указват
броят на срещанията му в низа). Резултатът да е под формата на RLE списък, в
който всеки символ се среща наймного
веднъж