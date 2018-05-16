Para correr el proyecto:

1.  `docker-compose up --build`
2.  Abrir `http://localhost:7474`
3.  Ingresar con el user `neo4j` y password `test`
4.  Correr el comando `create (:User{name:"admin",password:"admin",email:"test@test.com"})` para crear un usuario inicial (los demás usuarios se pueden crear desde la plataforma)
5.  Abrir `http://localhost` e ingresar con el user `admin` y password `admin`
