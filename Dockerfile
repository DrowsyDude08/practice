# Используем минимальный образ Ubuntu
FROM ubuntu:22.04

# Устанавливаем необходимые пакеты
RUN apt update && apt install -y gcc socat && rm -rf /var/lib/apt/lists/*

# Копируем исходный код и компилируем
COPY vuln.c /home/ctf/vuln.c
WORKDIR /home/ctf
RUN gcc vuln.c -o vuln -no-pie -fno-stack-protector

# Создаём флаг
RUN echo "practice{command_injection_success}" > /home/ctf/flag.txt

# Запускаем сервис
CMD ["socat", "TCP-LISTEN:1337,reuseaddr,fork", "EXEC:/home/ctf/vuln"]