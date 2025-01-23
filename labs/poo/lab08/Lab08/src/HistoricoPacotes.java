import java.util.ArrayList;

public class HistoricoPacotes {
    private ArrayList<Pacote> historico;

    public void adicionarAoHistorico(Pacote pacote) {
        historico.add(pacote);
    }

    public void exibirHistorico() {
        for (Pacote p : historico) {
            System.out.println(p.toString());
        }
    }

    public HistoricoPacotes() {
        this.historico = new ArrayList<Pacote>();
    }
}
