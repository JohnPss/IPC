import java.util.Queue;
import java.util.LinkedList;

public class FilaEntradaPacotes {
    private Queue<Pacote> fila;

    public void adicionarPacote(Pacote pacote) {
        fila.add(pacote);
    }

    public Pacote removerPacote() {
        return fila.poll();
    }

    public void exibirFila() {
        for (Pacote p : fila) {
            System.out.println(p.toString());
        }
    }

    public boolean isEmpty() {
        return fila.isEmpty();
    }

    public FilaEntradaPacotes() {
        this.fila = new LinkedList<Pacote>();
    }
}
