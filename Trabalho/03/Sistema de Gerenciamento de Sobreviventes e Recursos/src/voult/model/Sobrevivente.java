package voult.model;

import voult.util.*;
import voult.enums.StatusSobreviventeEnum;
import voult.enums.HabilidadeEnum;
import java.util.ArrayList;

public class Sobrevivente extends Pessoa {
    private ArrayList<HabilidadeEnum> habilidades;
    private StatusSobreviventeEnum status;

    public boolean addHabilidade(HabilidadeEnum habilidade) {
        if (habilidadeJaExiste(habilidade)) {
            throw new IllegalArgumentException("Habilidade já existe.");
        }
        if (habilidades.size() >= 3) {
            throw new IllegalStateException("Número máximo de habilidades atingido.");
        }
        habilidades.add(habilidade);
        return true;
    }

    public boolean removerHabilidade(HabilidadeEnum habilidade) {
        if (habilidades.contains(habilidade)) {
            habilidades.remove(habilidade);
            return true;
        }
        return false;
    }

    public ArrayList<HabilidadeEnum> getHabilidades() {
        if (habilidades.isEmpty()) {
            throw new IllegalStateException("Sobrevivente nao tem habilidades.");
        }
        return new ArrayList<>(habilidades);
    }

    public boolean habilidadeJaExiste(HabilidadeEnum hab) {
        return habilidades.contains(hab);
    }

    public void validarHabilidadeExiste(HabilidadeEnum hab) {
        if (habilidadeJaExiste(hab)) {
            System.out.println("Habilidade existe: " + hab);
        } else {
            throw new IllegalArgumentException("Habilidade ja existe.");
        }
    }

    public void setHabilidades(ArrayList<HabilidadeEnum> habilidades) {
        this.habilidades = habilidades;
    }

    public StatusSobreviventeEnum getStatus() {
        return status;
    }

    public void setStatus(StatusSobreviventeEnum status) {
        this.status = status;
    }

    public Sobrevivente(String nome, int idade,
            StatusSobreviventeEnum status) {
        super(nome, idade, IDGenerator.nextUUID());
        this.habilidades = new ArrayList<>();
        this.status = status;
    }
}
