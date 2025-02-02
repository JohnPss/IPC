package collections;

import model.Produto;

import java.util.ArrayList;
import java.util.List;

import exceptions.ProductNotFoundException;

public class ListaProdutos<T extends Produto> {
    private List<T> produtos;

    public ListaProdutos() {
        this.produtos = new ArrayList<>();
    }

    public void adicionarProduto(T product) {
        produtos.add(product);
    }

    public T acharProduto(int id) throws ProductNotFoundException {
        return produtos.stream()
                .filter(p -> p.getId() == id)
                .findFirst()
                .orElseThrow(() -> new ProductNotFoundException("ID: " + id + " nao achado."));
    }

    public List<T> getTodosProdutos() {
        return new ArrayList<>(produtos);
    }
}