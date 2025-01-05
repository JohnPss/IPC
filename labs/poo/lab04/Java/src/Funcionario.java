public class Funcionario {
    private String nome;
    private int salario_base;

    public Funcionario(String nome, int salario_base) {
        this.nome = nome;
        this.salario_base = salario_base;
    }

    public String descricao() {
        return "Funcionario: " + this.nome + " Salario: " + this.salario_base;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getSalario_base() {
        return salario_base;
    }

    public void setSalario_base(int salario_base) {
        this.salario_base = salario_base;
    }

}
