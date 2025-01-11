package voult.model;

import voult.util.*;
import voult.enums.StatusSobreviventeEnum;
import voult.enums.HabilidadeEnum;
import java.util.ArrayList;

public class Sobrevivente extends Pessoa {
    private ArrayList<HabilidadeEnum> habilidades;
    private StatusSobreviventeEnum status;

    public boolean addHabilidade(HabilidadeEnum habilidade) {
        if (!habilidades.contains(habilidade) && habilidades.size() < 3) {
            habilidades.add(habilidade);
            return true;
        }
        return false;
    }

    public boolean removerHabilidade(HabilidadeEnum habilidade) {
        if (habilidades.contains(habilidade)) {
            habilidades.remove(habilidade);
            return true;
        }
        return false;
    }

    public ArrayList<HabilidadeEnum> getHabilidades() {
        return new ArrayList<>(habilidades);
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
