package lab03.src;

import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

public class Curso {
    private String nome;
    private HashMap<Integer, Aluno> alunos;
    private HashMap<Integer, Professor> professores;
    private List<Diciplina> diciplinas;

    public Curso(String nome) {
        this.nome = nome;
        this.alunos = new HashMap<Integer, Aluno>();
        this.professores = new HashMap<Integer, Professor>();
        this.diciplinas = new ArrayList<>();
    }

    // public String getNome() {
    // return nome;
    // }

    // public HashMap<Integer, Aluno> getAlunos() {
    // return alunos;
    // }

    // public HashMap<Integer, Professor> getProfessores() {
    // return professores;
    // }

    // public List<Diciplina> getDiciplinas() {
    // return diciplinas;
    // }

    // public void setNome(String nome) {
    // this.nome = nome;
    // }

    // public void setAlunos(List<Aluno> alunos) {
    // this.alunos = alunos;
    // }

    // public void setProfessores(List<Professor> professores) {
    // this.professores = professores;
    // }

    // public void setDiciplinas(List<Diciplina> diciplinas) {
    // this.diciplinas = diciplinas;
    // }

    public void addAluno(Aluno aluno) {
        this.alunos.put(aluno.getMatricula(), aluno);
    }

    public void addProfessor(Professor professor) {
        this.professores.put(professor.getID(), professor);
    }

    public void addDiciplina(Diciplina diciplina) {
        this.diciplinas.add(diciplina);
    }

    public void imprimirAlunos() {
        for (Aluno aluno : alunos.values()) {
            System.out.println(aluno);
        }
    }

    public void imprimirProfessores() {
        for (Professor professor : professores.values()) {
            System.out.println(professor);
        }
    }

    public void imprimirDiciplinas() {
        for (Diciplina diciplina : diciplinas) {
            System.out.println(diciplina);
        }
    }

    @Override
    public String toString() {
        return "Curso{" +
                "nome='" + nome + '\'' +
                ", alunos=" + alunos +
                ", professores=" + professores +
                ", diciplinas=" + diciplinas +
                '}';
    }
}
