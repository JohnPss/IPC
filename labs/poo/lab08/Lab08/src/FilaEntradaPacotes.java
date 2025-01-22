import java.util.Queue;

public class FilaEntradaPacotes {
    private Queue<Pacote> fila;

    public void adicionarPacote(Pacote pacote) {
        fila.add(pacote);
    }

    public Pacote removerPacote() {
        return fila.poll();
    }

    public void exbirFila() {
        for (Pacote p : fila) {
            p.toString();
        }
    }
}
