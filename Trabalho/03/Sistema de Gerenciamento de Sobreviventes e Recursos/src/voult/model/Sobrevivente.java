package voult.model;

import java.util.ArrayList;

public class Sobrevivente extends Pessoa {
    private ArrayList<String> habilidades;
    private String status;

    public ArrayList<String> getHabilidades() {
        return habilidades;
    }

    public void setHabilidades(ArrayList<String> habilidades) {
        this.habilidades = habilidades;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public Sobrevivente(String nome, int idade, String indentificador, ArrayList<String> habilidades, String status) {
        super(nome, idade, indentificador);
        this.habilidades = habilidades;
        this.status = status;
    }
}
