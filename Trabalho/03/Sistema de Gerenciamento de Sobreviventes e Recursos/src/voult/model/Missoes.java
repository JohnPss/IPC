package voult.model;

import voult.model.Missoes;
import java.util.ArrayList;

public class Missoes {
    private String nome;
    private String objetivo;
    private String local;
    private ArrayList<Sobrevivente> sobreviventes;
    private ArrayList<Recursos> recursos;
    private String status;

    public Missoes(String nome, String objetivo, String local, ArrayList<Sobrevivente> sobreviventes,
            ArrayList<Recursos> recursos, String status) {
        this.nome = nome;
        this.objetivo = objetivo;
        this.local = local;
        this.sobreviventes = sobreviventes;
        this.recursos = recursos;
        this.status = status;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getObjetivo() {
        return objetivo;
    }

    public void setObjetivo(String objetivo) {
        this.objetivo = objetivo;
    }

    public String getLocal() {
        return local;
    }

    public void setLocal(String local) {
        this.local = local;
    }

    public ArrayList<Sobrevivente> getSobreviventes() {
        return sobreviventes;
    }

    public void setSobreviventes(ArrayList<Sobrevivente> sobreviventes) {
        this.sobreviventes = sobreviventes;
    }

    public ArrayList<Recursos> getRecursos() {
        return recursos;
    }

    public void setRecursos(ArrayList<Recursos> recursos) {
        this.recursos = recursos;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

}
