import java.util.ArrayList;

public class HistoricoPacotes {
    private ArrayList<Pacote> historico;

    public void adicionarAoHistorico(Pacote pacote) {
        historico.add(pacote);
    }

    public void exbirHistorico() {
        for (Pacote p : historico) {
            p.toString();
        }
    }
}
