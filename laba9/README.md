# Задания на 3


1) Нахожусь на ветке main

![alt text](img/image.png)

2) git log выглядит так:

![alt text](img/image-1.png)

3) Добавился файл sort.c

![alt text](img/image-2.png)

4) sort.c убралась из списка файлов "Untracked files" и переместилась в список "Changes to be committed"

![alt text](img/image-3.png)

5) закоммитились 2 файла: README и sort.c

![alt text](img/image-4.png)

6) Исчезли файлы README (он исчез, просто я сразу добавляю в него информацию для отчёта) и sort.c из списка "Changes not staged for commit"

![alt text](img/image-5.png)

7) Файл sort.c снова появился в списке "Changes not staged for commit", но с припиской "modified"

![alt text](img/image-6.png)

8) sort.c снова в "Changes to be committed"

![alt text](img/image-7.png)

9) sort.c снова в "Changes not staged for commit". При вводе git commit появился новый коммит

![alt text](img/image-8.png)

10) Запушил

![alt text](img/image-9.png)

11) Создал новую ветку и переключился на неё. git status показывает в начале, что я нахожусь на другой ветке

![alt text](img/image-10.png)

12) Проверил, что нахожусь на ветке mybranch. Создал файл file1_Vlad.txt и закоммитил его. Проверил, что ветка указывает на новый коммит

![alt text](img/image-11.png)

13) Переключился на основную ветку. Исчез коммит, который был в другой ветке

![alt text](img/image-12.png)

14) Создал файл file2.txt и закоммитил его. Посмотрел, что ветки теперь две

![alt text](img/image-13.png)

15) Переключился на другую ветку. Файл file2.txt пропал и его коммит тоже

![alt text](img/image-14.png)


# Задания на 4


1) Показывает, что изменилось в коде.  git diff --staged пустой. После add стало наоборот

![alt text](img/image-15.png)

2) git diff показывает изменения в коде, которые я сделал сейчас, а git diff --staged показывает изменения в коде, которые были сделаны в прошлый раз

![alt text](img/image-16.png)

3) после того, как мы добавили строку printf(“hello git\n”) git status просто показывает, что sort.c 'Changes not staged for commit', после  git restore sort.c sort.c исчез

![alt text](img/image-17.png)

4) Создал новый файл на ветке main и закоммитил его

![alt text](img/image-18.png)

5) Создал новую ветку. В git status ничего необычного

![alt text](img/image-19.png)

6) Когда изменил текст, закоммитил его при использовании git log --oneline --graph --all появилась новая ветка

![alt text](img/image-20.png)

7) Переключился на main. Команда cat выдала приветствие в нижнем регистре

![alt text](img/image-21.png)

8) Из-за различной информации в одной и той же строке возник конфликт

![alt text](img/image-22.png)

9) Удалил ветку

![alt text](img/image-23.png)

10) Смержил main и mybranch

![alt text](img/image-24.png)


# Задание на 5


1) Создал новую ветку, переключился на неё, создал там файл и закоммитил его

![alt text](img/image-25.png)

2) Переместился на ветку main, создал там файл и закоммитил его. git log --oneline --graph --all показывает оба комммита

![alt text](img/image-26.png)

3) Как и написано в задании, смержить не удалось. Ошибка произошла потому что в одинаковых строках содержится разная информация. git status показывает, что 2 файла несмерживаемые. Исправил, закоммитил

![alt text](img/image-27.png)

4) Создал mergesort.py, добавил туда содержимое, закоммитил. Создал новую ветку Mergesort-Impl и переключился на неё

![alt text](img/image-28.png)

5) Изменил содержимое питоновского файла и закоммитил это. Переключился на ветку main и поменял содержимое этого же файла, но на другой ветке. В отличие от git log с флагом -all, git log --oneline --graph показывает коммиты только ветки main, т.е. коммита питоновского файла, который был на другой ветке, нет

![alt text](img/image-29.png)