package voult.model;

import voult.enums.StatusSobreviventeEnum;
import voult.enums.HabilidadeEnum;
import java.util.ArrayList;

public class Sobrevivente extends Pessoa {
    private ArrayList<HabilidadeEnum> habilidades;
    private StatusSobreviventeEnum status;

    public void addHabilidade(HabilidadeEnum habilidade) {
        habilidades.add(habilidade);
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

    public Sobrevivente(String nome, int idade, String indentificador, ArrayList<HabilidadeEnum> habilidades,
            StatusSobreviventeEnum status) {
        super(nome, idade, indentificador);
        this.habilidades = habilidades;
        this.status = status;
    }
}
