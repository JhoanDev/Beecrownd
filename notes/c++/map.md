### 🧾 `std::map` – Resumo de Métodos

| Método                          | O que faz                                                   | Complexidade     |
|--------------------------------|--------------------------------------------------------------|------------------|
| `m[key]`                        | Acessa ou insere `key`, retorna referência ao valor         | O(log n)         |
| `m.at(key)`                    | Acessa valor de `key`; lança exceção se não existir         | O(log n)         |
| `m.insert({key, val})`        | Insere o par `{key, val}` se a chave não existir            | O(log n)         |
| `m.erase(key)`                | Remove elemento com a chave `key`                           | O(log n)         |
| `m.erase(it)`                 | Remove o elemento apontado por `it`                         | O(1)             |
| `m.find(key)`                 | Retorna iterador para `key` ou `m.end()` se não encontrar   | O(log n)         |
| `m.count(key)`                | Retorna 0 ou 1 se a chave existe                            | O(log n)         |
| `m.clear()`                   | Remove todos os elementos                                   | O(n)             |
| `m.size()`                    | Retorna o número de elementos                               | O(1)             |
| `m.empty()`                   | Verifica se o mapa está vazio                               | O(1)             |
| `m.lower_bound(key)`         | Retorna iterador para 1ª chave >= `key`                     | O(log n)         |
| `m.upper_bound(key)`         | Retorna iterador para 1ª chave > `key`                      | O(log n)         |
| `m.begin(), m.end()`         | Iteradores para início e fim                                | O(1)             |
| `m.rbegin(), m.rend()`       | Iteradores reversos                                         | O(1)             |

---

### 📌 Características

- Estrutura baseada em **árvore balanceada (RB-Tree)**.
- Mantém os elementos **ordenados pelas chaves**.
- Cada chave é única — duplicatas não são permitidas.
- `m[key]` cria a chave com valor default se não existir.

