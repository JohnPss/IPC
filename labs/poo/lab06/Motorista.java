public class Motorista {
    private String nome;
    private String cpf;
    private String cnh;

    public Motorista(String nome, String cpf, String cnh) {
        this.nome = nome;
        this.cpf = cpf;
        this.cnh = cnh;
    }

    public String getDetalhes() {
        return "Nome: " + nome + ", CPF: " + cpf + ", CNH: " + cnh;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getCnh() {
        return cnh;
    }

    public void setCnh(String cnh) {
        this.cnh = cnh;
    }

}