package lab03.src;

public class Aluno extends Pessoa {
    private int matricula;

    public Aluno(String nome, String endereco, int matricula) {
        super(nome, endereco);
        this.matricula = matricula;
    }

    public int getMatricula() {
        return matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    @Override
    public String toString() {
        return "Aluno [matricula=" + matricula + ", nome=" + getNome() + ", endereco=" + getEndereco() + "]";
    }

}
