public class TechLead extends Funcionario implements DesenvolverInterface, GerenteInterface {
    private String linguagem_principal;
    private int numero_de_equipes;

    public TechLead(String linguagem_principal, int numero_de_equipes) {
        this.linguagem_principal = linguagem_principal;
        this.numero_de_equipes = numero_de_equipes;
    }
}
