# CPP Module 08 — Guía para preparar la evaluación

Esta guía resume qué debe demostrar cada ejercicio, qué puede preguntar el evaluador y cómo responder sin depender del `main.cpp` original.

## Preparación general

Antes de entrar en cada ejercicio:

```bash
make re
make clean
make fclean
make re
```

Comprueba que:

- Compila con `c++ -std=c++98 -Wall -Wextra -Werror`.
- No existe `using namespace`.
- No existe `friend`.
- No se usan funciones prohibidas como `malloc`, `calloc`, `realloc`, `free`, `printf`, etc.
- No se usan características de C++11 posteriores.
- Los Makefiles tienen las reglas `all`, `clean`, `fclean`, `re` y `PHONY`.
- No se necesita el binario en el repositorio.
- Los headers no contienen declaraciones de funciones usadas exclusivamente por el `main` de pruebas.
- El evaluador puede reemplazar el `main.cpp` y compilar contra los headers.

### Preguntas generales

**¿Por qué se permite usar STL en este módulo?**

Porque el módulo introduce contenedores, iteradores y algoritmos estándar. La implementación debe apoyarse en herramientas como `std::find`, `std::sort` o el contenedor subyacente de `std::stack`.

**¿Qué significa que el código siga C++98?**

Debe compilar en modo C++98 y no usar inicialización moderna, `auto`, `nullptr`, listas de inicialización con llaves, ranges, lambdas ni otras funcionalidades posteriores.

**¿Los métodos implementados dentro de una plantilla cuentan como función implementada en un header?**

Sí están permitidos cuando forman parte de una función o clase plantilla. Los métodos no plantilla deben declararse en el header y definirse en un `.cpp`.

**¿Qué sucede si el evaluador usa otro `main`?**

Debe seguir funcionando. El `main` de pruebas no puede ser necesario para que se vinculen las clases o funciones exigidas.

---

## Ex00 — Easy find

### Resultado que debe existir

- Un archivo `easyfind.hpp`.
- Opcionalmente puede existir `easyfind.tpp`.
- Una función plantilla llamada `easyfind`.
- Compatibilidad con al menos `std::vector<int>`, `std::list<int>` y `std::deque<int>`.
- Uso obligatorio de `std::find`.
- Lanzamiento de una excepción o devolución de un valor de error cuando no haya coincidencia.

Ejemplo conceptual:

```cpp
template <typename T>
int easyfind(T const &container, int target)
{
    typedef typename T::const_iterator Iterator;

    Iterator result = std::find(container.begin(), container.end(), target);
    if (result == container.end())
        throw std::invalid_argument("value not found");
    return *result;
}
```

### Punto caliente: tipos const o no const

`std::find` devuelve un iterador. Para un contenedor recibido como `T const &`, debe usarse `T::const_iterator`. Si el contenedor se recibe como `T &`, puede usarse `T::iterator`.

### Punto caliente: contenedor vacío

Una búsqueda sobre un contenedor vacío también debería terminar con una excepción o un resultado de error. Los evaluadores suelen probarlo explícitamente.

### `main` mínimo esperado

Debe demostrar:

- Un valor encontrado en un `std::vector`.
- Un valor encontrado en otro contenedor permitido, como `std::list` o `std::deque`.
- Un valor inexistente.
- Un contenedor vacío.

También deben mostrar un resultado comprensible sin depender de macros de color o afirmaciones internas.

### Preguntas habituales

**¿Por qué se usa `std::find` y no un bucle manual?**

Porque el enunciado exige el uso de algoritmos STL. Además, `std::find` convierte el concepto de búsqueda en una operación reutilizable mediante iteradores.

**¿Por qué no se usa `T::value_type`?**

La firma se puede escribir con el tipo entero del enunciado. Lo importante es que el contenedor exponga `begin()`, `end()` e iteradores compatibles con `std::find`.

**¿Qué excepción es mejor?**

No existe una excepción obligatoria. Se acepta `std::invalid_argument`, `std::runtime_error`, `std::out_of_range` u otra excepción que tenga sentido, siempre que el comportamiento sea coherente. Si se lanza una excepción en el código, el `main` debe capturarla o dejar claro que puede propagarse.

**¿Puede el evaluador usar otro contenedor?**

El enunciado pide como mínimo vector, list y deque. Una función bien escrita debería funcionar con cualquier contenedor secuencial cuyos iteradores sean válidos para `std::find`.

**¿Puede tener ANSI de colores en el header?**

Es mejor no tenerlos. Los colores no forman parte de la API y pueden aparecer dentro de mensajes cuando el evaluador compara texto. Los mensajes de error deben ser simples y independientes del `main`.

### Evidencia rápida

```bash
./easyfind
```

Debe mostrar resultados encontrados y tratar correctamente los casos no encontrados.

---

## Ex01 — Span

### Resultado que debe existir

- Una clase `Span`.
- Constructor con capacidad: `Span(unsigned int n)`.
- Constructor por defecto si se implementa según el diseño.
- Constructor de copia y operador de asignación.
- Destructor.
- `addNumber(int)`.
- `shortestSpan()`.
- `longestSpan()`.
- Una forma práctica de añadir varios números, normalmente `addRange(first, last)`.

### Orthdox Canonical Form

Aunque el enunciado no exige literalmente repetir una clase no-interfaz para toda clase, el evaluador puede comprobar que `Span` sea seguro al copiarse. Debe tener:

- Constructor por defecto si se usa.
- Constructor de copia.
- Operador de asignación.
- Destructor.

No tienen sentido funciones virtuales porque `Span` no es una interfaz.

### Punto caliente: capacidad y longitud

La diferencia entre capacidad máxima y elementos almacenados debe mantenerse correctamente:

```cpp
if (_lenStored >= _nMax)
    throw std::overflow_error("Span: span is full");
```

Debe lanzar al intentar insertar después de alcanzar `N` elementos.

### Punto caliente: menos de dos números

`shortestSpan()` y `longestSpan()` deben lanzar una excepción si el `Span` contiene cero o un elemento.

No está permitido devolver simplemente `0` como si fuera válido.

### Punto caliente: `shortestSpan()`

La forma correcta es:

1. Crear una copia vectorial o ordenar una copia de los datos.
2. Ejecutar `std::sort` sobre esa copia.
3. Comparar números adyacentes.
4. Devolver la diferencia mínima.

Complejidad esperada: $O(n \log n)$.

No es suficiente tomar solo el mínimo y el segundo mínimo. Tampoco se debe hacer una comparación de todos los pares, que sería $O(n^2)$.

Ejemplo:

```cpp
std::vector<int> sorted = _store;
std::sort(sorted.begin(), sorted.end());

int shortest = INT_MAX;
for (size_t i = 0; i + 1 < sorted.size(); ++i)
{
    int difference = sorted[i + 1] - sorted[i];
    if (difference < shortest)
        shortest = difference;
}
return shortest;
```

### Punto caliente: desbordamiento entero

Restar dos `int` puede desbordar. Por ejemplo, `INT_MAX - INT_MIN` excede el rango de `int`. Una implementación robusta usa `long long` o compara primero y trata el valor fuera de rango según el diseño.

Esto es importante porque `longestSpan()` debe poder manejar valores extremos sin comportamiento indefinido.

### Punto caliente: `addRange` o método equivalente

Debe permitir añadir varios números desde un par de iteradores:

```cpp
template <typename InputIterator>
void addRange(InputIterator first, InputIterator last);
```

Debe:

- Aceptar cualquier rango válido.
- Añadir todos los valores.
- Lanzar si el rango supera la capacidad.
- Mantener mínimos y máximos actualizados.
- Actualizar correctamente la longitud almacenada.

También puede usarse `std::vector.begin()`/`std::vector.end()`, arrays o cualquier iterador compatible.

### Preguntas habituales

**¿Qué algoritmo se puede usar para el menor span?**

`std::sort` es suficiente. El sujeto permite STL en este módulo. Tras ordenar, comparar posiciones adyacentes es correcto.

**¿Qué excepciones deben lanzarse?**

La mayoría usa:

- `std::invalid_argument` para menos de dos elementos.
- `std::overflow_error` o `std::out_of_range` para capacidad llena.
- `std::out_of_range` para un índice inválido si se implementa `operator[]`.

No hay nombres de excepción únicos exigidos por el sujeto, pero el comportamiento debe ser razonable y probado.

**¿Por qué no se modifica directamente `_store` sin actualizar los valores mínimos y máximos?**

`longestSpan()` necesita calcular el máximo y mínimo. Si se utilizan variables cacheadas, deben mantenerse consistentes después de `addNumber`, `addRange`, copia y asignación.

**¿Qué pasa si se asigna un Span a sí mismo?**

El operador de asignación debe tratar la autoasignación. Guardar una copia temporal o comprobar `if (this != &src)` evita corrupción y es seguro.

**¿Qué tipo devuelve `operator[]` si se implementa?**

Puede devolver `int &` y lanzar si el índice no existe. No es obligatorio si el sujeto no lo pide, pero si existe debe tener sentido.

**¿Por qué añadir rangos es mejor que llamar a `addNumber` muchas veces?**

Permite usar iteradores, puede rellenar 10 000 o más números y evita bucles externos innecesarios en el usuario. También demuestra el uso de plantillas con iteradores.

### Prueba de referencia

```text
Entrada: 6, 3, 17, 9, 11
shortestSpan: 2
longestSpan: 14
```

### Prueba adicional recomendada

- `Span(10000)` con un vector de 10 000 valores.
- `Span(1)`: demasiados pocos números.
- Intentar añadir al span lleno.
- Añadir rangos parciales.
- Mínimo y máximo iguales.
- Valores negativos y números extremos.
- Copia y asignación.

---

## Ex02 — Mutated abomination

### Resultado que debe existir

- Una clase `MutantStack<T, Container>`.
- Herencia pública o privada/protegida de `std::stack<T, Container>`.
- Iterador tipo `iterator`.
- Métodos `begin()` y `end()`.
- Versiones `const` de `begin()` y `end()`.
- Funcionamiento con el contenedor predeterminado `std::deque<T>`.
- Funcionamiento con `std::list<T>`.

Ejemplo mínimo:

```cpp
typedef typename Container::iterator iterator;

typedef typename Container::const_iterator const_iterator;

iterator begin()
{
    return this->c.begin();
}

iterator end()
{
    return this->c.end();
}

const_iterator begin() const
{
    return this->c.begin();
}

const_iterator end() const
{
    return this->c.end();
}
```

### Punto caliente: el contenedor protegido `c`

`std::stack` contiene `c` como miembro protegido. Por eso una clase derivada puede acceder a él mediante `this->c`.

No debe recrear otro contenedor separado o duplicar el estado del stack.

### Punto caliente: el orden de iteración

`begin()` debe corresponder al fondo de la pila y `end()` al final del contenedor subyacente. Así un iterador recorre el contenido desde el primer elemento insertado hasta el último:

```text
[5, 3, 5, 737, 0]
```

No tiene que recorrer la pila en el orden de `top()` porque el sujeto pide iteración sobre el contenedor subyacente.

### Punto caliente: const correctness

Una instancia constante debe permitir iteradores constantes. Deben existir dos sobrecargas:

```cpp
iterator begin();
const_iterator begin() const;

iterator end();
const_iterator end() const;
```

`top()`, `push()`, `pop()` y demás miembros de `std::stack` siguen disponibles gracias a la herencia.

### Punto caliente: segundo parámetro de contenedor

Aunque el ejemplo de materia puede mostrar solo `MutantStack<int>`, una solución robusta permite:

```cpp
MutantStack<int, std::list<int> > stack;
```

Esto exige que `Container::iterator` y `Container::const_iterator` existan.

### Canonical Form en esta plantilla

Debido a que hereda de `std::stack`, conviene implementar:

- Constructor por defecto.
- Constructor de copia.
- Operador de asignación.
- Destructor.

La implementación habitual delega en `std::stack<T, Container>`:

```cpp
MutantStack(MutantStack const &src)
    : std::stack<T, Container>(src)
{}

MutantStack &operator=(MutantStack const &src)
{
    std::stack<T, Container>::operator=(src);
    return *this;
}
```

El constructor no necesita inicializar `c`, porque ya lo hace la clase base.

### Prueba del sujeto

```cpp
MutantStack<int> mstack;

mstack.push(5);
mstack.push(17);
mstack.push(3);
mstack.push(5);
mstack.push(737);
mstack.push(0);
mstack.pop();

for (MutantStack<int>::iterator it = mstack.begin();
     it != mstack.end(); ++it)
{
    std::cout << *it << std::endl;
}
```

Resultado esperado:

```text
5
17
3
5
737
```

Nota: si el evaluador presenta primero `std::cout << mstack.top();`, tras empujar los valores y ejecutar `pop()` el `top()` debe ser `737`, no `0`.

### Prueba con `std::list`

La misma iteración debe funcionar cuando se usa `std::list<int>` como contenedor subyacente:

```cpp
MutantStack<int, std::list<int> > mstack;
```

### Preguntas habituales

**¿Por qué se hereda de `std::stack`?**

Porque `std::stack` es una clase diseñada como adaptador de contenedor y su miembro subyacente `c` está protegido. La herencia permite exponer iteradores sin reimplementar push, pop, top y size.

**¿Por qué no se usa `std::vector` internamente en todos los casos?**

No hace falta. El contenedor predeterminado puede ser `std::deque`. El segundo parámetro permite decidir el contenedor subyacente.

**¿Qué pasa si el evaluador usa un contenedor que no tiene iterador bidireccional?**

El sujeto pide un contenedor iterable. Como mínimo se espera deque y list. Si el evaluador prueba otro contenedor, este debe tener iteradores compatibles con el tipo definido.

**¿Deben existir métodos `rbegin()` o `rend()`?**

No los pide el sujeto. Un evaluador normal comprobará `begin()`, `end()` y posiblemente sus versiones `const`.

**¿Puede modificarse el contenedor desde un iterador?**

Sí, el `iterator` debe permitir modificar elementos si el contenedor subyacente lo permite. La versión `const_iterator` no debe permitir modificaciones.

---

## Checklist final para la evaluación

### Ex00

- [ ] Existe `easyfind.hpp`.
- [ ] El `main` prueba encontrado, no encontrado y vacío.
- [ ] Se usa `std::find`.
- [ ] Funciona con vector, list y deque.
- [ ] No hay declaraciones de funciones de test dentro del header.
- [ ] El error no depende de macros o colores.

### Ex01

- [ ] Existe `Span.hpp` y `Span.cpp`.
- [ ] La clase tiene constructor, copia, asignación y destructor.
- [ ] `addNumber()` comprueba capacidad.
- [ ] `shortestSpan()` devuelve el menor valor entre elementos adyacentes tras ordenar.
- [ ] `longestSpan()` usa el mínimo y máximo.
- [ ] Menos de dos elementos lanza una excepción.
- [ ] Existe `addRange` u otra forma práctica de añadir rangos.
- [ ] El `main` contiene una prueba de al menos 10 000 elementos.
- [ ] No usa complejidad $O(n^2)$ para el menor span.

### Ex02

- [ ] Existe `MutantStack.hpp`.
- [ ] Hereda de `std::stack`.
- [ ] Expone `begin()` y `end()`.
- [ ] Expone versiones `const`.
- [ ] El ejemplo del sujeto produce el resultado esperado.
- [ ] También funciona con `std::list`.
- [ ] El `main` tiene más pruebas que el ejemplo simple.

## Comandos finales

```bash
cd CPP_Module_08
make -C ex00 re
make -C ex01 re
make -C ex02 re
./ex00/easyfind
./ex01/span
./ex02/mutantStack
make -C ex00 fclean
make -C ex01 fclean
make -C ex02 fclean
```

Recuerda dejar el proyecto limpio al final si así lo prefieres, aunque normalmente debes comprobar primero que la compilación y ejecución funcionan.
