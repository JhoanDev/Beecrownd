### 🧾 `std::vector` – Resumo de Métodos

| Método                         | O que faz                                           | Complexidade     |
|-------------------------------|-----------------------------------------------------|------------------|
| `v.size()`                    | Retorna o número de elementos                       | O(1)             |
| `v.empty()`                   | Retorna `true` se o vetor está vazio                | O(1)             |
| `v.push_back(x)`             | Adiciona `x` ao final                               | O(1) amortizado  |
| `v.pop_back()`               | Remove o último elemento                           | O(1)             |
| `v[i]` ou `v.at(i)`          | Acessa o i-ésimo elemento                          | O(1)             |
| `v.front()`                  | Acessa o primeiro elemento                         | O(1)             |
| `v.back()`                   | Acessa o último elemento                           | O(1)             |
| `v.insert(pos, x)`          | Insere `x` na posição `pos`                        | O(n)             |
| `v.erase(pos)`              | Remove o elemento em `pos`                         | O(n)             |
| `v.erase(a, b)`             | Remove os elementos no intervalo `[a, b)`          | O(n)             |
| `v.clear()`                  | Remove todos os elementos                          | O(n)             |
| `v.resize(n)`               | Redimensiona o vetor para conter `n` elementos     | O(n)             |
| `v.reserve(n)`              | Aloca espaço para pelo menos `n` elementos         | O(n)             |
| `v.capacity()`              | Retorna a capacidade alocada                       | O(1)             |
| `v.begin(), v.end()`        | Retorna iteradores para início e fim               | O(1)             |
| `v.rbegin(), v.rend()`      | Iteradores reversos                                | O(1)             |
| `sort(v.begin(), v.end())`  | Ordena os elementos                                | O(n log n)       |

---

### 🧠 Observações

- `v.at(i)` verifica limites e lança exceção se `i` for inválido (mais seguro que `v[i]`).
- `reserve()` é útil para evitar realocações repetidas se você sabe o tamanho final.
- Inserções e remoções no meio são custosas (O(n)), pois precisam mover elementos.