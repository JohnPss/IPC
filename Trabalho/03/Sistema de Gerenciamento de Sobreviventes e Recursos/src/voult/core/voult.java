package voult.core;

import java.util.ArrayList;
import voult.model.*;

public class voult {
    private ArrayList<Sobrevivente> sobreviventes;
    private ArrayList<Recurso> recursos;
    private ArrayList<Missao> missoes;

    public voult() {
        this.sobreviventes = new ArrayList<>();
        this.recursos = new ArrayList<>();
        this.missoes = new ArrayList<>();
    }

    public boolean addSobrevivente(Sobrevivente sobrevivente) {
        if (!this.sobreviventes.contains(sobrevivente)) {
            this.sobreviventes.add(sobrevivente);
            return true;
        }
        return false;
    }

    public boolean addRecurso(Recurso recurso) {
        if (!this.recursos.contains(recurso)) {
            this.recursos.add(recurso);
            return true;
        }
        return false;
    }

    public boolean addMissao(Missao missao) {
        if (!this.missoes.contains(missao)) {
            this.missoes.add(missao);
            return true;
        }
        return false;
    }

    public ArrayList<Sobrevivente> getSobreviventes() {
        return new ArrayList<>(this.sobreviventes);
    }

    public Sobrevivente getSobrevivente(String nome) {
        for (Sobrevivente sobrevivente : this.sobreviventes) {
            if (sobrevivente.getNome().equals(nome)) {
                return sobrevivente;
            }
        }
        return null;
    }

    public void exibirSobreviventes() {
        for (Sobrevivente sobrevivente : this.sobreviventes) {
            System.out.println(sobrevivente.getHabilidades());
        }
    }

    // poder encontrar recurso e sobrevivente por missao

}
