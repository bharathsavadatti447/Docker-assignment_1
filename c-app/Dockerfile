FROM gcc:latest
WORKDIR /c-app
COPY prime.c /c-app/prime.c
RUN gcc -o prime prime.c
EXPOSE 3306
CMD ["./prime"]
