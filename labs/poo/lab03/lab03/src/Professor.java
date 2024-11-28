package lab03.src;

import java.util.Random;

public class Professor extends Pessoa {
    private String titulacao;
    private String curso;
    private int ID;

    public Professor(String nome, String endereco, String titulacao, String curso) {
        super(nome, endereco);
        this.titulacao = titulacao;
        this.curso = curso;
        this.ID = generateRandomId();
    }

    private int generateRandomId() {
        Random random = new Random();
        return 100 + random.nextInt(900);
    }

    public String getTitulacao() {
        return titulacao;
    }

    public void setTitulacao(String titulacao) {
        this.titulacao = titulacao;
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    public int getID() {
        return ID;
    }

    @Override
    public String toString() {
        return "Professor{" +
                "titulacao='" + titulacao + '\'' +
                ", curso='" + curso + '\'' +
                ", nome='" + getNome() + '\'' +
                ", endereco='" + getEndereco() + '\'' +
                '}';
    }

}
