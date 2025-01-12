package voult.core;

import voult.enums.*;
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
        if (!existeRecursoNome(recurso)) {
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

    public void exibirRecursos() {
        for (Recurso recurso : this.recursos) {
            System.out.println(
                    recurso.getNome().getValor() + " - " + recurso.getNome().name() + ": " + recurso.getQuantidade());
        }
    }

    public boolean existeRecursoNome(Recurso recurso) {
        for (Recurso rec : this.recursos) {
            if (rec.getNome().equals(recurso.getNome())) {
                return true;
            }
        }
        return false;
    }

    public boolean addQuantidadeEspecifica(Recurso recurso) {
        for (Recurso rec : this.recursos) {
            if (rec.getNome().equals(recurso.getNome())) {
                rec.adicionarQuantidade(recurso.getQuantidade());
                return true;
            }
        }
        return false;
    }

    // troca nome
    public boolean consumirRecurso(TipoRecursoEnum tipo, int quantidade) {
        Recurso recurso = encontrarRecurso(tipo);
        if (recurso != null && quantidade > 0) {
            return recurso.consumirQuantidade(quantidade);
        }
        return false;
    }

    public Recurso encontrarRecurso(TipoRecursoEnum tipo) {
        return recursos.stream()
                .filter(r -> r.getNome().equals(tipo))
                .findFirst()
                .orElse(null);
    }
    // poder encontrar recurso e sobrevivente por missao
}
