
### 🧾 Membros e Operações

| Membro / Operação      | O que faz                                                             | Complexidade |
| ------------------------ | --------------------------------------------------------------------- | ------------ |
| `first`                | Acessa o primeiro valor do par                                        | O(1)         |
| `second`               | Acessa o segundo valor do par                                         | O(1)         |
| `pair<T1, T2> p(a, b)` | Construtor: cria um `pair`com os valores `a`e `b`               | O(1)         |
| `operator<`            | Ordenação padrão: compara `first`; em empate, compara `second` | O(1)         |
| `operator==`           | Verifica se os dois pares são iguais                                 | O(1)         |
| `operator!=`           | Verifica se são diferentes                                           | O(1)         |
| `operator>`            | Maior que (`<`invertido)                                            | O(1)         |
| `operator<=`           | Menor ou igual                                                        | O(1)         |
| `operator>=`           | Maior ou igual                                                        | O(1)         |

---

### 🛠️ Funções Auxiliares

| Função            | O que faz                                             | Complexidade |
| ------------------- | ----------------------------------------------------- | ------------ |
| `make_pair(a, b)` | Cria um `pair`com tipos deduzidos de `a`e `b`   | O(1)         |
| `tie(a, b)`       | Cria um `tuple`que permite desempacotar um `pair` | O(1)         |
| `swap(p1, p2)`    | Troca dois pares                                      | O(1)         |

**Exemplo com `make_pair`:**

```cpp
auto p = make_pair(42, "resposta");
cout << p.first << ", " << p.second;  // Saída: 42, resposta
```

**Exemplo com `tie`:**

```cpp
pair<int, string> p = {1, "oi"};
int x;
string y;
tie(x, y) = p;  // x = 1, y = "oi"
```

---

### 🎯 Quando Usar

* Retornar dois valores de uma função.
* Armazenar pares (como coordenadas 2D, intervalos, chave-valor temporários).
* Ordenações personalizadas com `vector<pair<>>`.
