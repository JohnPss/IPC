package voult.model;

import voult.enums.TipoRecursoEnum;

public class Recurso {
    private TipoRecursoEnum nome;
    private int quantidade;

    public Recurso(TipoRecursoEnum nome, int quantidade) {
        this.nome = nome;
        this.quantidade = quantidade;
    }

    public TipoRecursoEnum getNome() {
        return nome;
    }

    public void setNome(TipoRecursoEnum nome) {
        this.nome = nome;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        if (quantidade >= 0) {
            this.quantidade = quantidade;
        } else {
            throw new IllegalArgumentException("Quantidade não pode ser negativa");
        }
    }

    public boolean consumirQuantidade(int quantidade) {
        if (quantidade <= this.quantidade && quantidade > 0) {
            this.quantidade -= quantidade;
            return true;
        }
        return false;
    }

    public void adicionarQuantidade(int quantidade) {
        if (quantidade > 0) {
            this.quantidade += quantidade;
        } else {
            throw new IllegalArgumentException("Quantidade a adicionar deve ser positiva");
        }
    }

}
