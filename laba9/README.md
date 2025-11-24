Нахожусь на ветке main
![alt text](image.png)

git log выглядит так:
![alt text](image-1.png)

Добавился файл sort.c
![alt text](image-2.png)

sort.c убралась из списка файлов "Untracked files" и переместилась в список "Changes to be committed"
![alt text](image-3.png)

закоммитились 2 файла: README и sort.c
![alt text](image-4.png)

Исчезли файлы README (он исчез, просто я сразу добавляю в него информацию для отчёта) и sort.c из списка "Changes not staged for commit"
![alt text](image-5.png)

Файл sort.c снова появился в списке "Changes not staged for commit", но с припиской "modified"
![alt text](image-6.png)

sort.c снова в "Changes to be committed"
![alt text](image-7.png)

sort.c снова в "Changes not staged for commit". При вводе git commit появился новый коммит
![alt text](image-8.png)

Запушил
![alt text](image-9.png)

Создал новую ветку и переключился на неё. git status показывает в начале, что я нахожусь на другой ветке
![alt text](image-10.png)

Проверил, что нахожусь на ветке mybranch. Создал файл file1_Vlad.txt и закоммитил его. Проверил, что ветка указывает на новый коммит
![alt text](image-11.png)

Переключился на основную ветку. Исчез коммит, который был в другой ветке
![alt text](image-12.png)

Создал файл file2.txt и закоммитил его. Посмотрел, что ветки теперь две
![alt text](image-13.png)

Переключился на другую ветку. Файл file2.txt пропал и его коммит тоже
![alt text](image-14.png)