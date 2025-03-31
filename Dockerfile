FROM ubuntu:22.04

RUN apt update && apt install -y gcc socat && rm -rf /var/lib/apt/lists/*

COPY vuln.c /home/ctf/vuln.c
WORKDIR /home/ctf
RUN gcc vuln.c -o vuln -no-pie -fno-stack-protector

CMD ["socat", "TCP-LISTEN:1337,reuseaddr,fork", "EXEC:/home/ctf/vuln"]