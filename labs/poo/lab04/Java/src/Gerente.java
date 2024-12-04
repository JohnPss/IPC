public class Gerente implements GerenteInterface {
    private int numero_de_equipes;

    public int getNumero_de_equipes() {
        return numero_de_equipes;
    }

    public void setNumero_de_equipes(int numero_de_equipes) {
        this.numero_de_equipes = numero_de_equipes;
    }

    public Gerente(int numero_de_equipes) {
        this.numero_de_equipes = numero_de_equipes;
    }

    @Override
    public int bonus() {
        return this.numero_de_equipes * 500;
    }

}
