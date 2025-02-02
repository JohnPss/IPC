package model;

public class Produto {
    private int id;
    private String drescicao;
    private double preco;
    private int estoque;

    public Produto(int id, String drescicao, double preco, int estoque) {
        this.id = id;
        this.drescicao = drescicao;
        this.preco = preco;
        this.estoque = estoque;
    }

    public Produto(int id, String drescicao) {
        this(id, drescicao, 10.0, 5);
    }

    public int getId() {
        return id;
    }

    public String getDrescicao() {
        return drescicao;
    }

    public double getPreco() {
        return preco;
    }

    public int getEstoque() {
        return estoque;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public void setEstoque(int estoque) {
        this.estoque = estoque;
    }

    @Override
    public String toString() {
        return "Id: " + id +
                ", Drescicao: '" + drescicao + '\'' +
                ", Preco: " + preco +
                ", Estoque: " + estoque;
    }
}