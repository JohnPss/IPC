package lab03.src;

public class Diciplina {
    private String nome;
    private int CH;
    private Professor professor;

    public Diciplina(String nome, int CH, Professor professor) {
        this.nome = nome;
        this.CH = CH;
        this.professor = professor;
    }

    public String getNome() {
        return nome;
    }

    public int getCH() {
        return CH;
    }

    public Professor getProfessor() {
        return professor;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCH(int CH) {
        this.CH = CH;
    }

    public void setProfessor(Professor professor) {
        this.professor = professor;
    }

    @Override
    public String toString() {
        return "Diciplina{" +
                "nome='" + nome + '\'' +
                ", CH=" + CH +
                ", professor=" + professor +
                '}';
    }

}
