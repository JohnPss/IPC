public class Desenvolvedor implements DesenvolverInterface {
    private String linguagem_principal;

    public Desenvolvedor(String linguagem_principal) {
        this.linguagem_principal = linguagem_principal;
    }

    @Override
    public String projetos_realizados() {
        return "Projetos realizados na linguem: " + this.linguagem_principal;
    }

    @Override
    public String getLinguagem_principal() {
        return linguagem_principal;
    }

    @Override
    public void setLinguagem_principal(String linguagem_principal) {
        this.linguagem_principal = linguagem_principal;
    }
}
