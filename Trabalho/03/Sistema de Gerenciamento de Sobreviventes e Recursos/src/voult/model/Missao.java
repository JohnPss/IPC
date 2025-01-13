package voult.model;

import voult.enums.*;
import voult.model.Missao;
import java.util.ArrayList;

public class Missao {
    private String nome;
    private String objetivo;
    private String local;
    private ArrayList<String> sobreviventes;
    private ArrayList<Recurso> recursos;
    private StatusMissaoEnum status;

    public Missao(String nome, String objetivo, String local,
            ArrayList<Recurso> recursos, StatusMissaoEnum status) {
        this.nome = nome;
        this.objetivo = objetivo;
        this.local = local;
        this.sobreviventes = new ArrayList<>();
        this.recursos = recursos;
        this.status = status;
    }

    public void exibirSobreviventes() {
        for (String sobrevivente : sobreviventes) {
            System.out.println(sobrevivente);
        }
    }

    public void adicionarRecurso(Recurso recurso) {
        this.recursos.add(recurso);
    }

    public boolean adicionarSobrevivente(String identificador) {
        if (sobreviventes.size() < 5 && !sobreviventes.contains(identificador)) {
            return sobreviventes.add(identificador);
        }
        throw new IllegalArgumentException("Número máximo de sobreviventes atingido");
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

    public ArrayList<String> getSobreviventes() {
        return new ArrayList<>(sobreviventes);
    }

    public void setSobreviventes(ArrayList<String> sobreviventes) {
        this.sobreviventes = sobreviventes;
    }

    public ArrayList<Recurso> getRecursos() {
        return new ArrayList<>(recursos);
    }

    public void setRecursos(ArrayList<Recurso> recursos) {
        this.recursos = recursos;
    }

    public StatusMissaoEnum getStatus() {
        return status;
    }

    public void setStatus(StatusMissaoEnum status) {
        this.status = status;
    }

}
