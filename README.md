# Command Injection Challenge

## Описание

В этой задаче пользователю предстоит исследовать уязвимость командной инъекции в простом C-приложении. Приложение использует функцию `system()` для выполнения команд, переданных через ввод пользователя. Уязвимость возникает из-за недостаточной проверки ввода, что позволяет злоумышленнику выполнить произвольные команды.

## Уязвимость

В приложении существует уязвимость командной инъекции. Пользователь может передать вредоносную команду, которая будет выполнена в системе. Это позволяет выполнить произвольный код, что представляет собой классическую уязвимость для большинства приложений, использующих `system()` без должной фильтрации ввода.

## Задание

Ваша задача — найти способ выполнить командную инъекцию, чтобы извлечь флаг из переменной окружения, которая задаётся в контейнере через переменную `FLAG`.

Флаг находится в переменной окружения и задаётся при запуске контейнера. Вам нужно воспользоваться уязвимостью командной инъекции, чтобы успешно получить флаг.

## Запуск

1. Клонируйте репозиторий и перейдите в директорию проекта.
    
2. Постройте и запустите контейнер с помощью `docker-compose`:
    
    ```bash
    docker-compose up --build
    ```
    
3. Подключитесь к сервису через netcat:
    
    ```bash
    nc localhost 1337
    ```
    
4. Введите данные, содержащие командную инъекцию, для того чтобы вывести флаг.
    

## Объяснение

Приложение уязвимо к командной инъекции, так как оно использует функцию `system()` для выполнения команд без надлежащей проверки ввода. Для того чтобы извлечь флаг, нужно передать такой ввод, который позволит выполнить команду, извлекающую флаг из переменной окружения, переданной через Docker.

## Способы защиты

Чтобы защитить приложение от командной инъекции, необходимо:

- Использовать функции, которые безопасно выполняют команды, например, `execvp()`, вместо `system()`.
    
- Ограничивать возможные символы в пользовательском вводе (например, `;`, `|`).
    
- Использовать библиотеки для безопасного выполнения команд с параметрами.
    