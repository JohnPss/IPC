public class Gerente extends Funcionario implements GerenteInterface {
    private int numero_de_equipes;

    public int getNumero_de_equipes() {
        return numero_de_equipes;
    }

    public void setNumero_de_equipes(int numero_de_equipes) {
        this.numero_de_equipes = numero_de_equipes;
    }

    public Gerente(int numero_de_equipes, String nome, int salario_base) {
        super(nome, salario_base);
        this.numero_de_equipes = numero_de_equipes;
    }

    @Override
    public int bonus() {
        return this.numero_de_equipes * 500;
    }

    @Override
    public String descricao() {
        return "Gerente: " + this.getNome() + "\nSalario: " + this.getSalario_base() + "\nNumero de equipes: "
                + this.numero_de_equipes + "\nBonus: " + this.bonus();
    }

}
