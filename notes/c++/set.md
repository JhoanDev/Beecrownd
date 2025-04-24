## 🌲 `std::set`

`std::set` é uma estrutura baseada em árvore binária balanceada (geralmente uma Red-Black Tree) que armazena elementos **únicos** em **ordem crescente** por padrão.

---

### 🧾 Métodos Importantes

| Método                | O que faz                                                    | Complexidade |
| ---------------------- | ------------------------------------------------------------ | ------------ |
| `s.insert(x)`        | Insere `x` se ainda não estiver presente                  | O(log n)     |
| `s.erase(x)`         | Remove `x` se estiver presente                             | O(log n)     |
| `s.erase(it)`        | Remove o elemento apontado por `it`                        | O(log n)     |
| `s.find(x)`          | Retorna iterador para `x` ou `s.end()` se não encontrar | O(log n)     |
| `s.count(x)`         | Retorna 1 se `x` está no conjunto, 0 caso contrário      | O(log n)     |
| `s.lower_bound(x)`   | Iterador para o primeiro elemento `>= x`                   | O(log n)     |
| `s.upper_bound(x)`   | Iterador para o primeiro elemento `> x`                    | O(log n)     |
| `s.size()`           | Retorna número de elementos                                 | O(1)         |
| `s.empty()`          | Retorna true se o conjunto estiver vazio                     | O(1)         |
| `s.clear()`          | Remove todos os elementos                                    | O(n)         |
| `s.begin(), s.end()` | Iteradores para início e fim                                | O(1)         |

---

### 🛠️ Funções Auxiliares

| Função           | O que faz                                                         | Complexidade |
| ------------------ | ----------------------------------------------------------------- | ------------ |
| `swap(s1, s2)`   | Troca os conteúdos de dois sets                                  | O(1)         |
| `equal_range(x)` | Retorna par de iteradores:`lower_bound(x)` e `upper_bound(x)` | O(log n)     |

---

### 🎯 Características

- **Elementos únicos**: Não permite elementos repetidos.
- **Ordenado automaticamente**: Por padrão, ordem crescente (pode ser personalizada com comparator).
- **Busca e inserção eficientes**: O(log n) por operação.
- **Baseado em árvore**: Mantém os elementos ordenados, diferente de `unordered_set`.

---

### 🔍 Exemplo Rápido

```cpp
set<int> s;
s.insert(5);
s.insert(1);
s.insert(3);

for (int x : s) cout << x << " ";  // Saída: 1 3 5

if (s.find(2) == s.end()) cout << "2 não encontrado!";
```
