public class TechLead extends Funcionario implements DesenvolverInterface, GerenteInterface {
    private String linguagem_principal;
    private int numero_de_equipes;

    public TechLead(String linguagem_principal, int numero_de_equipes, String nome, int salario_base) {
        super(nome, salario_base);
        this.linguagem_principal = linguagem_principal;
        this.numero_de_equipes = numero_de_equipes;
    }

    @Override
    public String descricao() {
        return "TechLead: " + this.getNome() + "\n" +
                "Salario: " + this.getSalario_base() + "\n" +
                "Numero de equipes: " + this.numero_de_equipes + "\n" +
                "Linguagem principal: " + linguagem_principal + "\n" +
                "Bonus: " + this.bonus();
    }

    @Override
    public String projetos_realizados() {
        return "Projetos realizados na linguem: " + this.linguagem_principal;
    }

    @Override
    public int bonus() {

        return this.numero_de_equipes * 500;
    }

}
