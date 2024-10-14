package entities;

public class funcionarios {

    private String nome;

    private Integer cpf;

    private String email;

    private String telefone;

    private Double salario;

    private String cargo;

    public funcionarios(String nome, Integer cpf, String email, String telefone, Double salario, String cargo) {

        this.nome = nome;

        this.cpf = cpf;

        this.email = email;

        this.telefone = telefone;

        this.salario = salario;

        this.cargo = cargo;

    }

    public String getNome() {
        return nome;
    }

    public Integer getCpf() {
        return cpf;
    }

    public String getEmail() {
        return email;
    }

    public String getTelefone() {
        return telefone;
    }

    public double getSalario() {
        return salario;
    }

    public String getCargo() {
        return cargo;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public void setCargo(String cargo) {
        this.cargo = cargo;
    }

    @Override
    public String toString() {
        return "Nome: " + nome + "\nCPF: " + cpf + "\nEmail: " + email + "\nTelefone: " + telefone + "\nSalário: "
                + salario + "\nCargo: " + cargo;
    }

}
