package model;

import java.util.ArrayList;
import java.util.List;
import exceptions.*;

public class Pedido {
    private int codigoPedido;
    private String clienteNome;
    private List<Produto> itens;
    private double valorTotal;

    public Pedido(int codigoPedido, String clienteNome) {
        this.codigoPedido = codigoPedido;
        this.clienteNome = clienteNome;
        this.itens = new ArrayList<>();
        this.valorTotal = 0.0;
    }

    public Pedido() {

    }

    public void addProduto(Produto produto) throws InsufficientStockException {
        if (produto.getEstoque() <= 0) {
            throw new InsufficientStockException("Produto " + produto.getDrescicao() + " esta sem estoque");
        }
        itens.add(produto);
        produto.setEstoque(produto.getEstoque() - 1);
        valorTotal += produto.getPreco();
    }

    public List<Produto> getProdutos() {
        return itens;

    }

    public String getClienteNome() {
        return clienteNome;
    }

    public int getCodigoPedido() {
        return codigoPedido;
    }

    public double getValorTotal() {
        return valorTotal;
    }

    @Override
    public String toString() {
        return "Codigo: " + codigoPedido +
                ", itens: " + itens +
                ", valorTotal: " + valorTotal;
    }
}
