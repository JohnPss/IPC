public class Desenvolvedor extends Funcionario {
    private String linguagem_principal;

    public Desenvolvedor(String linguagem_principal, String nome, int salarioB) {
        super(nome, salarioB);
        this.linguagem_principal = linguagem_principal;
    }

    public String projetos_realizados() {
        return "Projetos realizados na linguem: " + this.linguagem_principal;
    }

    public String getLinguagem_principal() {
        return linguagem_principal;
    }

    public void setLinguagem_principal(String linguagem_principal) {
        this.linguagem_principal = linguagem_principal;
    }

    @Override
    public String descricao() {
        return "Desenvolvedor: " + this.getNome() + "\n" +
                "Salario: " + this.getSalario_base() + "\n" +
                "Linguagem principal: " + this.linguagem_principal;
    }
}
