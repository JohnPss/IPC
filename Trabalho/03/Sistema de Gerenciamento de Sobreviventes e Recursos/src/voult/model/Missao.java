package voult.model;

import voult.enums.*;
import voult.model.Missao;
import java.util.ArrayList;

public class Missao {
    private String nome;
    private String objetivo;
    private String local;
    private ArrayList<Sobrevivente> sobreviventes;
    private ArrayList<Recurso> recursos;
    private StatusMissaoEnum status;

    public Missao(String nome, String objetivo, String local, ArrayList<Sobrevivente> sobreviventes,
            ArrayList<Recurso> recursos, StatusMissaoEnum status) {
        this.nome = nome;
        this.objetivo = objetivo;
        this.local = local;
        this.sobreviventes = sobreviventes;
        this.recursos = recursos;
        this.status = status;
    }

    public void exibirSobreviventes() {
        for (Sobrevivente sobrevivente : this.sobreviventes) {
            System.out.println("Nome: " + sobrevivente.getNome());
            System.out.println("Idade: " + sobrevivente.getIdade());
            System.out.println("Habilidades: ");
            for (HabilidadeEnum habilidade : sobrevivente.getHabilidades()) {
                System.out.println(habilidade);
            }
            System.out.println("Status: " + sobrevivente.getStatus());
        }
    }

    public void adicionarRecurso(Recurso recurso) {
        this.recursos.add(recurso);
    }

    public void adicionarSobrevivente(Sobrevivente sobrevivente) {
        this.sobreviventes.add(sobrevivente);
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
        return new ArrayList<>(sobreviventes);
    }

    public void setSobreviventes(ArrayList<Sobrevivente> sobreviventes) {
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
