package lab03.src;

import java.util.Random;

public class Aluno extends Pessoa {
    private int matricula;

    public Aluno(String nome, String endereco) {
        super(nome, endereco);
        this.matricula = generateRandomId();
    }

    private int generateRandomId() {
        Random random = new Random();
        return 100 + random.nextInt(900);
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
