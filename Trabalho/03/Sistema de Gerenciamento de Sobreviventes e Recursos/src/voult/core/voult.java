package voult.core;

import voult.enums.*;
import java.util.ArrayList;
import java.util.Map;
import java.util.Objects;
import java.util.stream.Collectors;

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
        throw new IllegalArgumentException("Missão já cadastrada");
    }

    public ArrayList<Sobrevivente> getSobreviventes() {
        return new ArrayList<>(this.sobreviventes);
    }

    public Sobrevivente getSobrevivente(String ID) {
        for (Sobrevivente sobrevivente : this.sobreviventes) {
            if (sobrevivente.getIndentificador().equals(ID)) {
                return sobrevivente;
            }
        }
        return null;
    }

    public void exibirSobreviventes() {
        for (Sobrevivente sobrevivente : this.sobreviventes) {
            System.out.println(sobrevivente.getNome() + " - " + sobrevivente.getIndentificador());
            try {
                System.out.println(sobrevivente.getHabilidades());
            } catch (IllegalStateException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    public void exibirSobreviventesHabilidades() {
        for (Sobrevivente sobrevivente : this.sobreviventes) {
            System.out.println(sobrevivente.getNome() + " - " + sobrevivente.getIndentificador() + "- "
                    + sobrevivente.getStatus());
            try {
                System.out.println(sobrevivente.getHabilidades());
            } catch (IllegalStateException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    // public void exibirHabilidadesSobrevivente(Sobrevivente sobrevivente) {
    // System.out.println(sobrevivente.getNome() + " - " +
    // sobrevivente.getHabilidades());
    // }

    public void exibirMissoes() {
        for (Missao missao : this.missoes) {
            System.out.println(missao.getNome() + " - " + missao.getStatus());
        }
    }

    public void exibirRecursos() {
        for (Recurso recurso : this.recursos) {
            System.out.println(
                    recurso.getNome().getValor() + " - " + recurso.getNome().name() + ": " + recurso.getQuantidade());
        }
    }

    public void exibirMissoesRealizadas() {
        for (Missao missao : this.missoes) {
            System.out.println(missao.getNome() + " - " + missao.getStatus());
            try {
                exibirSobreviventesNaMissao(missao);
            } catch (IllegalStateException e) {
                System.out.println(e.getMessage());
            }
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

    public Sobrevivente encontrarSobrevivente(String identificador) {
        return sobreviventes.stream()
                .filter(s -> s.getIndentificador().equals(identificador))
                .findFirst()
                .orElse(null);
    }

    public Recurso encontrarRecurso(TipoRecursoEnum nome) {
        return recursos.stream()
                .filter(r -> r.getNome().equals(nome))
                .findFirst()
                .orElse(null);
    }

    public Missao encontrarMissao(String nome) {
        return missoes.stream()
                .filter(m -> m.getNome().equals(nome))
                .findFirst()
                .orElse(null);
    }

    public void exibirSobreviventesNaMissao(Missao missao) {
        Map<String, Sobrevivente> sobreviventesMap = sobreviventes.stream()
                .collect(Collectors.toMap(
                        Sobrevivente::getIndentificador,
                        s -> s));

        boolean hasSurvivors = missao.getSobreviventes().stream()
                .map(sobreviventesMap::get)
                .filter(Objects::nonNull)
                .peek(sobrevivente -> {
                    System.out.println(sobrevivente.getNome());
                    System.out.println("Habilidades: " + sobrevivente.getHabilidades());
                    System.out.println("Status: " + sobrevivente.getStatus());
                })
                .count() > 0;

        if (!hasSurvivors) {
            throw new IllegalStateException("Nenhum sobrevivente encontrado na missão.");
        }
    }

    // poder encontrar recurso e sobrevivente por missao
}

/*
 * public void exibirSobreviventesNaMissao(Missao missao) {
 * Map<String, Sobrevivente> sobreviventesMap = sobreviventes.stream()
 * .collect(Collectors.toMap(
 * Sobrevivente::getIndentificador,
 * s -> s));
 * 
 * missao.getSobreviventes().stream()
 * .map(sobreviventesMap::get)
 * .filter(Objects::nonNull)
 * .map(Sobrevivente::getNome)
 * .forEach(System.out::println);
 * }
 * 
 */