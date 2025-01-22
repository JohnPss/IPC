public class Pacote implements Comparable<Pacote> {
    private int codigoPacote;
    private String descricao;
    private int prioridade;

    public int getPrioridade() {
        return prioridade;
    }

    private String CPF;

    Pacote(int codigoPacote, String descricao, int prioridade, String CPF) {
        this.codigoPacote = codigoPacote;
        this.descricao = descricao;
        this.prioridade = prioridade;
        this.CPF = CPF;
    }

    public int compareTo(Pacote outroPacote) {
        return Integer.compare(this.prioridade, outroPacote.prioridade);
    }

    public String toString() {
        return "Pacote: " + codigoPacote + " Descricao: " + descricao + " Prioridade: " + prioridade + " CPF: " + CPF;

    }
}