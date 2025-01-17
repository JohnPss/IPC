package voult.model;

public class Pessoa {
    private String nome;
    private int idade;
    private final String indentificador;

    public Pessoa(String nome, int idade, String indentificador) {
        this.nome = nome;
        this.idade = idade;
        this.indentificador = indentificador;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getIndentificador() {
        return indentificador;
    }
}
