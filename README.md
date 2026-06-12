# Sistema de Registro de Películas Multiusuario

## Descripción
Este proyecto es un sistema de registro de películas vistas por usuarios, desarrollado en C++ utilizando Programación Orientada a Objetos (OOP). El sistema permite registrar múltiples usuarios, cada uno con un ID automático y un documento único, registrar las películas vistas por cada usuario (título, duración y género), listar las películas de un usuario ordenadas por duración de mayor a menor y calcular el tiempo total dedicado al cine de manera recursiva. La interacción se realiza mediante un menú de consola intuitivo.

## Estructura del proyecto
- `main.cpp`: Contiene todas las clases (`Usuario`, `Pelicula`) y la lógica del menú interactivo.

### Clases principales
**Pelicula**
- Atributos: `titulo` (string), `duracion` (int), `genero` (string)
- Métodos: `mostrar()`, `getTitulo()`, `getDuracion()`, `getGenero()`

**Usuario**
- Atributos: `id` (int, automático), `documento` (string, único), `nombre` (string), `peliculas` (vector<Pelicula>)
- Métodos: `agregarPelicula(Pelicula)`, `mostrarPeliculasOrdenadas()`, `calcularTiempoTotal()`, `getId()`, `getDocumento()`, `getNombre()`

## Funcionalidades
1. Registrar usuario: Cada usuario recibe un ID automático y debe tener un documento único, evitando duplicados.
2. Registrar películas vistas por un usuario: Permite ingresar varias películas con título, duración y género.
3. Listar películas de un usuario: Muestra las películas ordenadas de mayor a menor duración.
4. Calcular tiempo total dedicado al cine: Suma recursiva de la duración de todas las películas de un usuario.

## Menú de usuario
Al seleccionar las opciones 2, 3 o 4, se muestra la lista de usuarios registrados y se permite seleccionar el usuario por su ID.

## Ejemplo de uso
1. Registrar usuario Ronald, documento `12345`.
2. Registrar usuario Ana, documento `67890`.
3. Seleccionar un usuario por ID para ingresar sus películas.
4. Listar películas de un usuario (ordenadas de mayor a menor duración
