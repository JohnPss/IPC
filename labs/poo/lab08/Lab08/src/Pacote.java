public class Pacote implements Comparable<Pacote> {
    private int codigoPacote;
    private String descricao;
    private int prioridade;
    private String cpf;

    public Pacote(int codigoPacote, String descricao, int prioridade, String cpf) {
        this.codigoPacote = codigoPacote;
        this.descricao = descricao;
        this.prioridade = prioridade;
        this.cpf = cpf;
    }

    public int compareTo(Pacote outro) {
        return Integer.compare(this.prioridade, outro.prioridade);
    }

    @Override
    public String toString() {
        return "Pacote [codigoPacote=" + codigoPacote + ", cpf=" + cpf + ", descricao=" + descricao + ", prioridade="
                + prioridade + "]";
    }
}
