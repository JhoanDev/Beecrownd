### 🧾 `std::unordered_map` – Resumo de Métodos

| Método                            | O que faz                                                   | Complexidade     |
|----------------------------------|--------------------------------------------------------------|------------------|
| `m[key]`                          | Acessa ou insere `key`, retorna referência ao valor         | O(1) médio, O(n) pior caso |
| `m.at(key)`                       | Acessa valor de `key`; lança exceção se não existir         | O(1)             |
| `m.insert({key, val})`           | Insere o par `{key, val}` se a chave não existir            | O(1) médio, O(n) pior caso |
| `m.erase(key)`                   | Remove elemento com a chave `key`                           | O(1) médio, O(n) pior caso |
| `m.erase(it)`                    | Remove o elemento apontado por `it`                         | O(1)             |
| `m.find(key)`                    | Retorna iterador para `key` ou `m.end()` se não encontrar   | O(1) médio, O(n) pior caso |
| `m.count(key)`                   | Retorna 0 ou 1 se a chave existe                            | O(1) médio, O(n) pior caso |
| `m.clear()`                       | Remove todos os elementos                                   | O(n)             |
| `m.size()`                        | Retorna o número de elementos                               | O(1)             |
| `m.empty()`                       | Verifica se o mapa está vazio                               | O(1)             |
| `m.bucket_count()`               | Retorna número de "baldes" (buckets)                        | O(1)             |
| `m.load_factor()`                | Retorna a carga média dos baldes (número de elementos por balde) | O(1)             |
| `m.begin(), m.end()`             | Iteradores para início e fim                                | O(1)             |
| `m.bucket(key)`                  | Retorna o número do balde em que a chave `key` está         | O(1)             |
| `m.rehash(n)`                    | Reorganiza a tabela para ter no mínimo `n` buckets          | O(n)             |

---

### 📌 Características

- **Tabela de hash**: Não garante a ordem dos elementos.
- **Acesso rápido**: O acesso e a modificação dos elementos são muito rápidos (O(1) médio).
- **Chaves únicas**: Não permite chaves duplicadas.
- Pode ter **colisões** (dois elementos hashando para o mesmo balde), o que pode degradar o desempenho para O(n) em pior caso.
- **Redimensionamento**: O `unordered_map` cresce automaticamente, distribuindo os elementos de forma mais equilibrada entre os baldes.

---

### 🎯 Vantagens sobre `map`
- **Mais rápido** em média (O(1) para busca e inserção, contra O(log n) no `map`).
- Não mantém os elementos ordenados — útil quando não há necessidade de ordenação.