import java.util.PriorityQueue;

public class FilaPrioridadePacotes {
    private PriorityQueue<Pacote> filaPrioritaria;

    public void adicionarPacote(Pacote pacote) {
        filaPrioritaria.add(pacote);
    }

    public Pacote removerPacote() {
        return filaPrioritaria.poll();
    }

    public void exbirFila() {
        for (Pacote p : filaPrioritaria) {
            p.toString();
        }
    }
}
